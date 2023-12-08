#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE


#include "spdlog/spdlog.h"
#include "StackOnList.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
//#include "spdlog/sinks/basic_file_sink.h"
//#include "spdlog/sinks/rotating_file_sink.h"


int main() {
		spdlog::set_level(spdlog::level::trace); // Set global log level to trace
		auto logger = spdlog::logger("console");
		spdlog::debug(typeid(logger).name());
		spdlog::trace("The stack app has run.");
		StackOnList* stack = new StackOnList();
		stack->push(1);
		StackOnList stack2;
		stack2.push(7);
		spdlog::trace("The stack app has finished.");
	return 0;
}