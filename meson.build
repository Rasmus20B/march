project ( 
  'march',
  'cpp',
  version: '0.0.1',
  license: 'GPL2',
  default_options: [
    'buildtype=release',
    'warning_level=3',
    'cpp_std=c++20'
  ]
)

protobuf_proj = subproject('protobuf')
protobuf_dep = dependency('protobuf', required : true) 
subdir('src')

build_tests = get_option('build_tests') and not is_subproject
if build_tests
subdir('test')
endif
