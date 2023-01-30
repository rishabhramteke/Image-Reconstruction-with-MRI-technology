# Image-Reconstruction-with-MRI-technology

I worked on this project during the spring of 2019 (my sophomore year) under the guidance of [Prof. V.M.Gadre](https://scholar.google.co.in/citations?user=vAoOAsQAAAAJ&hl=en)[LOR](./SAMEER_Letter.pdf) in collaboration with [SAMEER](https://www.sameer.gov.in) (Society for Applied Microwave Electronics Engineering & Research), an autonomous R&D laboratory under Ministry of Electronics & Information Technology, Government of India.

I was awarded the Undergraduate Research Award for this notable contribution.
We implemented a modified version of GRAPPA algorithm on SDK for image reconstruction with parallel MRI technology which would be used in the indigenous state-of-art MRI Machines. Simulated the algorithm on Matlab and then implemented it on Xilinx Zynq-7000 FPGA board.

The main MATLAB code is grappa.m and the main C++ code is grappainc.cpp

GRAPPA input:

![alt text](./results%20and%20comparision/input.png)

Output Image using GRAPPA algorithm on Kspace data:

![alt text](./results%20and%20comparision/result.png)

As part of this project, we also did an analysis of modulation and data transmission techniques. You can find our presentation [here](./URA.pdf)
