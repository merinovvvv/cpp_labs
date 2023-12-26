#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE


#include <iostream>
#include "spdlog/spdlog.h"
#include "StackOnList.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"


int main() {
	/*spdlog::set_level(spdlog::level::trace);*/ // Set global log level to trace
	/*auto logger = spdlog::logger("console");
	spdlog::debug(typeid(logger).name());
	spdlog::trace("The stack app has run.");
	StackOnList* stack = new StackOnList();
	stack->push(1);
	StackOnList stack2;
	stack2.push(7);
	spdlog::trace("The stack app has finished.");*/



	////SPDLOG:
	//CRITICAL - FATAL ERROR
	//error - ERROR
	//warn - WARNING
	//info - INFO
	//debug - DEBUG
	//trace - TRACE
	//
	//
	/*spdlog::set_level(spdlog::level::trace);
	spdlog::critical("critical");
	spdlog::error("error");
	spdlog::warn("warn");
	spdlog::info("info");
	spdlog::debug("debug");
	spdlog::trace("trace");*/

	spdlog::set_level(spdlog::level::trace); // настройка уровня вхождения
	spdlog::set_pattern("[%Y:%m:%d] [%H:%M:%S %z] [%n] [%^---%L---%$] %v");

	try
	{
		auto logger = spdlog::basic_logger_mt("default log-file", "logs/basic-log.txt");
		logger->info("Application started");
		StackOnList stack;

		stack.top();

		logger->info("Application finished");
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cerr << "Log init failed: " << ex.what() << std::endl;
		spdlog::critical("Log init failed.");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}

	/*spdlog::critical("critical");
	spdlog::error("error");
	spdlog::warn("warn");
	spdlog::info("info");
	spdlog::debug("debug");
	spdlog::trace("trace");

	printf("Number is %8.5f", 65.45);*/
	return 0;

	//spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
}