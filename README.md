# Loggy 
>Disclaimer: :warning: This tool is not meant to be *malicious*.

Loggy is an operating-system agnostic (works on Mac OSX, will work soon on Windows & Linux) key logger written in C.

Currently, the virtual key codes are sent straight to the standard output. The key codes aren't parsed into some human readable format either. For example, l = 37. If you press l 3 times, the standard output will look like 37 37 37.