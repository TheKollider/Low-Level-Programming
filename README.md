Low Level Programming


This module is focused on optimising a ray tracing algorithm provided to us and to be able to port that same code to work on either a playstation 4 dev kit or to linux.
I chose linux as working remotely from the university lab made it very difficult to have any time with the dev kit as they were only available on site, hench the choice to port to linux.

Optimisations:
Added threading to enable multiple frames to be compiled at the same time.
Created a memory pool to remove the need to find free memory and to enable walking the heap for debugging.
Removed string buffer when generating and saving the files, enabling writing directly to the file, increasing IO operation speed.
Ported to linux successfully and used macros to determine which OS code needs to run.