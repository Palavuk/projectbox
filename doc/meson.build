doxyfile = configuration_data()
doxyfile.set('OUTPUT_DIRECTORY', join_paths(meson.build_root(), 'doc'))
doxyfile.set('EXTRACT_ALL', 'YES')
input_files = meson.source_root()
doxyfile.set('INPUT', input_files)
configure_file(input: 'Doxyfile.in', output: 'Doxyfile', configuration: doxyfile)
    doxygen = find_program('doxygen')
if doxygen.found()
    run_target('doc', command: [doxygen, join_paths(meson.build_root(), 'doc', 'Doxyfile')])
endif
