# CBL
CBL is a library containing hexadecimal (base16), base32, and base64 encoding, the implementation is written in C and C++


### the library is compatible with MSVC here are the build steps :
  open "x64 Native Tools Command Prompt for VS 2019", then navigate to the root of the CBL folder then choose the version you want to build "C" or "C++" then do the following command "nmake build" this command will simply create the library that will be at the end of the compilation in the lib directory and which is named cbl_x64. lib, then you can create your main file or take as example the given file then compile it with the following command "cl.exe /TC example\main.c /link cbl_x64.lib" then launch the program.
 
 
 ### Exemple :
 
