#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE


#include <iostream>
#include "Matrix.h"

int main() {
    /*std::cout << "Matrix - The first vertion:\n";
    int n = 2, m = 3, l = 4;
    Matrix* first_matrix = new Matrix(n, m);
    Matrix* second_matrix = new Matrix(m, l);
    Matrix* result_matrix = new Matrix(n, l, 0);
    for (int i = 0; i < first_matrix->GetN(); i++) {
        for (int j = 0; j < second_matrix->GetM(); j++) {
            for (int k = 0; k < first_matrix->GetM(); k++) {
                result_matrix->GetA()[i][j] += first_matrix->GetA()[i][k] * second_matrix->GetA()[k][j];
            }
        }
    }
    std::cout << "Matrix multiplication:\n";
    result_matrix->show();*/
    auto logger = spdlog::stdout_color_mt("console");
    auto err_logger = spdlog::stderr_color_mt("stderr");

    logger->set_level(spdlog::level::warn);

    logger->trace("trace message");
    logger->debug("debug message");
    logger->info("info message");
    logger->warn("warn message");
    logger->error("error message");
    logger->critical("critical message");;


    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::trace); // Set global log level to debug
    spdlog::debug("This message should be displayed..");
    spdlog::trace("BIMBIMBAMBAM");
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");

    Matrix a(3, 3);
    std::cout << a << '\n';
    MatrixService tmp;
    tmp.trans(a);
    std::cout << a;
}