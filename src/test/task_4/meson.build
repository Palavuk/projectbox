foreach conf : [
	['where'    , gtest],
	['symmetric', gtest],
]
	test_name = conf[0] + '_test'
	executable_name = conf[0] + '_test'
	source_name = test_name + '.cpp'
	test(
		test_name,
		executable(
			executable_name,
			sources: source_name,
			include_directories: src,
			dependencies: conf[1],
		)
	)
endforeach