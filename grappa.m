load('E:\IIT BOMBAY\URA sameer\Raw_data_recon.mat')
newspace = fftshift(fft(ifftshift(image_data)));
for i = 1:128
    new_space(i,:,:) = newspace(i+128,:,:);
end
for i = 129:256
    new_space(i,:,:) = newspace(i-128,:,:);
end
pehla1 = new_space(:,:,1);
dusra1 = new_space(:,:,2);
combine1 = sqrt((pehla1^2 + dusra1^2));
sz = size(new_space);
number_of_coils= sz(3);
figure(1);
set(gcf,'Name',' K-Space - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imshow(real(log(new_space(:,:,n))),[]);axis square;title(strcat('Receiver-',num2str(n)));
end
colormap gray;
 
% figure(2),
% set(gcf,'Name','Magnitude images - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
% for n=1:number_of_coils
%     subplot(2,4,n); imagesc(abs(image_data(:,:,n)));axis square;title(strcat('Receiver-',num2str(n)));
% end
% colormap(gray)
% 
% figure(3)
% set(gcf,'Name','Coil combined image from scanner','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
% imagesc(sos);axis square;
% colormap(gray)

X = zeros(1,256,2);
P = zeros(1,1,1);
%disp(X);
%kspace(1,:,:) = new_space(1,:,:);
%kspace(100,:,:) = X;
i = 1;
while i < 101
    if mod(i,2) ==1
        kspace(i,:,:) = new_space(i,:,:);
    else
        kspace(i,:,:) = X;
    end
    i = i + 1;
end
for j=101:156
    kspace(j,:,:) = new_space(j,:,:);
end
K=157;
while K < 257
    if mod(K,2) ==0
        kspace(K,:,:) = new_space(K,:,:);
    else
        kspace(K,:,:) = X;
    end
    K = K + 1;
end
testspace= kspace;
 figure(2);
 set(gcf,'Name',' testspace','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
 for n=1:number_of_coils
     subplot(2,4,n); imshow(real(log(testspace(:,:,n))),[]);axis square;title(strcat('Receiver-',num2str(n)));
 end
 colormap gray;
 weights = [];
for m=1:256
    for j=101:156
        if mod(K,2) == 1
             output(j-100,:) = kspace(j,m,:);
             input(j-100,1) = kspace(j-3,m,1);
             input(j-100,2) = kspace(j-1,m,1);
             input(j-100,3) = kspace(j+1,m,1);
             input(j-100,4) = kspace(j+3,m,1);
             input(j-100,5) = kspace(j-3,m,2);
             input(j-100,6) = kspace(j-1,m,2);
             input(j-100,7) = kspace(j+1,m,2);
             input(j-100,8) = kspace(j+3,m,2);
        end
    end
    ans = (inv(((input)')*(input)))*(((input)')*(output));
    weights(:,:,m) = ans;
    %weights(:,:,m) = zeros(8,2);
end
for m=1:256
    i = 1;
    while i < 101
        if mod(i,2) ==1
            kspace(i,:,:) = kspace(i,:,:);
        else
            if i-3 > 0              
                in(1,1) = kspace(i-3,m,1);
            else 
                in(1,1) = P;
            end
            if i-1 > 0
                in(1,2) = kspace(i-1,m,1);
            else
                in(1,2) = P;
            end
            in(1,3) = kspace(i+1,m,1);
            in(1,4) = kspace(i+3,m,1);
            if i-3 > 0
                in(1,5) = kspace(i-3,m,2);
            else 
                in(1,5) = P;
            end
            if i-1 > 0
                in(1,6) = kspace(i-1,m,2);
            else 
                in(1,6) =P;
            end
            in(1,7) = kspace(i+1,m,2);
            in(1,8) = kspace(i+3,m,2);
            kspace(i,m,:) = (in)*(weights(:,:,m));
        end
        i = i + 1;
    end
    for j=101:156
        kspace(j,:,:) = kspace(j,:,:);
    end
    i=157;
    while i < 257
        if mod(i,2) ==0
            kspace(i,:,:) = kspace(i,:,:);
 
        else
                       
            inp(1,1) = kspace(i-3,m,1);
            inp(1,2) = kspace(i-1,m,1);
            if i+1 <257  
                inp(1,3) = kspace(i+1,m,1);
            else
                inp(1,3) = P;
            end
            if i+3 < 257
                inp(1,4) = kspace(i+3,m,1);
            else
                inp(1,4) = P;
            end
            inp(1,5) = kspace(i-3,m,2);
            inp(1,6) = kspace(i-1,m,2);
            if i+1 < 257
                inp(1,7) = kspace(i+1,m,2);
            else 
                inp(1,7) = P;
            end
            if i+3 < 257
                inp(1,8) = kspace(i+3,m,2);
            else 
                inp(1,8) = P;
            end
            kspace(i,m,:) = (inp)*(weights(:,:,m));
        end
        i = i + 1;
    end
end
pehla = kspace(:,:,1);
dusra = kspace(:,:,2);

final1 = fftshift(ifft(ifftshift(pehla)));
final2 = fftshift(ifft(ifftshift(dusra)));
combine = sqrt((final1.*final1 + final2.*final2));
figure(4);
set(gcf,'Name',' K-Space - final','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imshow(real(log(pehla)),[]);axis square;title(strcat('Receiver-',num2str(n)));
end
colormap gray;
figure(5),
set(gcf,'Name','Magnitude images - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imagesc(abs(image_data(:,:,n)));axis square;title(strcat('Receiver-',num2str(n)));
end
colormap(gray)
figure(6),
set(gcf,'Name','image - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imagesc(abs(fftshift(ifft(ifftshift(kspace(:,:,n))))));axis square;title(strcat('Receiver-',num2str(n)));
end
colormap(gray)
figure(7),
set(gcf,'Name','SOS - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),

subplot(2,4,1); imagesc(abs(combine));axis square;title(strcat('Receiver-',num2str(1)));

colormap(gray)