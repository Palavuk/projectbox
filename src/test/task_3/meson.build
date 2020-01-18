foreach conf : [
	['message', gtest],
	['cat'    , gtest],
	['uncat'    , gtest]
]
	test_name = conf[0] + '_test'
	executable_name = conf[0] + '_test'
	source_name = 'Source_test.cpp'
	test(
		test_name,
		executable(
			executable_name,
			sources: source_name,
			include_directories: src,
			dependencies: conf[1],
			link_with: variadic_lib
		)
	)
endforeach