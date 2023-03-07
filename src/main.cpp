

/*
    luis arandas 02-03-2023
    move tensors to gpu and forward pass
    simple instance of open pytorch models
*/

#include <filesystem>
#include <iostream>
#include <string>
#include <torch/script.h>
#include <torch/torch.h>


int main() {

    std::cout << "libtorch version: "
    << TORCH_VERSION_MAJOR << "."
    << TORCH_VERSION_MINOR << "."
    << TORCH_VERSION_PATCH << std::endl;

    // manually establish gpu device

    const int device_index = 0;
    std::string current_dir_str = std::filesystem::current_path().string();

    torch::Device device(torch::kCPU); // attach to cpu if unavailable
    std::cout << "cuda device count -> " << torch::cuda::device_count() << std::endl;

    if (torch::cuda::is_available()) {
        std::cout << "cuda is available! can train gpu" << std::endl;
        device = torch::Device(torch::kCUDA, device_index);
    }

    // move tensors to gpu

    torch::Tensor gpu_tensor_tst = torch::ones({2, 3}, device);
    std::cout << gpu_tensor_tst << std::endl;

}