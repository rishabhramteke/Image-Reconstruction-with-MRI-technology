load('C:\Users\RISHABH RAMTEKE\Downloads\Raw_data_recon.mat')
sz = size(kspace_data);
number_of_coils= sz(3);
figure(1);
set(gcf,'Name',' K-Space - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imshow(real(log(kspace_data(:,:,n))),[]);axis square;title(strcat('Receiver-',num2str(n)));
end
colormap gray;

figure(2),
set(gcf,'Name','Magnitude images - coil wise','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
for n=1:number_of_coils
    subplot(2,4,n); imagesc(abs(image_data(:,:,n)));axis square;title(strcat('Receiver-',num2str(n)));
end
colormap(gray)


figure(3)
set(gcf,'Name','Coil combined image from scanner','NumberTitle','off','units','normalized','outerposition',[0 0 1 1]),
imagesc(sos);axis square;
colormap(gray)

