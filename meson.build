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

sdl2_proj = subproject('sdl2')
sdl2_dep = dependency('sdl2', required : true) 
subdir('src')

build_tests = get_option('build_tests') and not is_subproject
if build_tests
subdir('test')
endif
