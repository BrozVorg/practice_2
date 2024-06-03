#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "ru");
    std::string videoPath;
    std::string outputDir;

    std::cout << "Введите путь к видеофайлу: ";
    std::getline(std::cin, videoPath);

    std::cout << "Введите папку для сохранения кадров: ";
    std::getline(std::cin, outputDir);

    std::string command = "ffmpeg -i \"" + videoPath + "\" \"" + outputDir +
        +"/frame_%04d.png\"";

    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Кадры успешно сохранены в папку: " << outputDir << std::endl;
    }
    else {
        std::cerr << "Ошибка при выполнении команды FFmpeg." << std::endl;
    }

    return 0;
}
