#packJPG


packJPG losslessly compresses JPEG files to a format labeled PJG, with the capacity to restore the compressed file to the original JPEG format. It typically reduces the file size of a JPEG file by 20%. Different versions of packJPG are incompatible, and the program produces an error message if you try to decompress PJG files with a different version than the one used for the compression.

* Version: 2.5k (older versions are available at http://www.elektronik.htw-aalen.de/packJPG/packjpg_m.htm)
* License: LGPLv3 (see [docs/lgpl-3.0.txt](lpgp-3.0.txt) for more information)
* Website: http://packjpg.encode.ru
* For questions and bug reports, contact packjpg (at) matthiasstirner.com
* Copyright 2006--2014 by HTW Aalen University and Matthias Stirner.

##Command Line Use


```
  Syntax: packjpg [file(s)] [options]
  Allowed options:
    -ver                       verify files after processing
    -v?                        level of verbosity; 0,1 or 2 is allowed (default 0)
    -np                        no pause after processing files
    -o                         overwrite existing files
    -p                         proceed on warnings
    -d                         discard image metadata.
```

File type is determined by file content, not by file extension.

Wildcards like "*.*" are supported, as is drag and drop of multiple files. Filenames for output files are created automatically. In default mode, files are never overwritten. If a filename is already in use, packJPG creates a new filename by adding underscores.

A file from stdin is denoted by the special name "-". In this case, output is written to stdout.

Some usage examples:
```
 packJPG *.pjg
 packJPG lena.jpg
 packJPG kodim??.jpg
 packJPG - < sail.pjg > sail.jpg
 ```
 
The program has a low error tolerance for images is a low error tolerance. Some JPEG files might not work with packJPG even if they work perfectly with other image processing software. By default, compression is cancelled on warnings. If warnings are skipped by using "-p", most files with warnings can also be compressed, but JPEG files reconstructed from PJG files might not be bitwise identical with the original JPEG files. There won't be any loss to image data or quality however.

Unnecessary meta information can be discarded using "-d". This reduces compressed files' sizes. Be warned though, reconstructed files won't be bitwise identical with the original files and meta information will be lost forever. As with "-p" there won't be any loss to image data or quality. 

There is no known case in which a file compressed by packJPG (without the "-p" option, see above) couldn't be reconstructed to exactly the state it was before. If you want an additional layer of safety you can also use the verify option "-ver". In this mode, files are compressed, then decompressed and the decompressed file compared to the original file. If this test doesn't pass there will be an error message and the compressed file won't be written to the drive. 

Please note that the "-ver" option should never be used in conjunction with the "-d" and/or "-p" options. As stated above, the "-p" and "-d" options will most likely lead to reconstructed JPG files not being bitwise identical to the original JPG files. In turn, the verification process may fail on various files although nothing actually went wrong. 

Usage examples:

 "packJPG -v1 -o baboon.pjg"
 "packJPG -ver lena.jpg"
 "packJPG -d tiffany.jpg"
 "packJPG -p *.jpg"


##Known Limitations 


packJPG is designed specifically to compress JPEG files, so it doesn't compress other file types.

### Drag and Drop


If you try to drag and drop to many files at once, there might be a windowed error message about missing privileges. In that case you can try it again with less files or consider using the command prompt. packJPG has been tested to work perfectly with thousands of files from the command line. This issue also happens with drag and drop in other applications, so it might not be a limitation of packJPG but a limitation of Windows.

##Acknowledgements


packJPG is the result of countless hours of research and development. It is part of Matthias Stirner final year project for Hochschule Aalen.

Prof. Dr. Gerhard Seelmann from Hochschule Aalen supported the development of packJPG with his extensive knowledge in the field of data compression. Without his advice, packJPG would not be possible.

The packJPG logo and icon are designed by Michael Kaufmann.

## Special Permissions

All programs in this package are free software; you can redistribute them and/or modify them under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version. 

The package is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details at http://www.gnu.org/copyleft/lgpl.html. 

If the LGPL v3 license is incompatible with your software project you might contact us and ask for a special permission to use the packJPG library under different conditions. In any case, usage of the packJPG algorithm under the LGPL v3 or above is highly advised and special permissions will only be given where necessary on a case by case basis. This offer is aimed mainly at closed source freeware developers seeking to add PJG support to their software projects. 

##History


v1.9a (04/20/2007) (non public)
 - first released version
 - only for testing purposes

v2.0  (05/28/2007) (public)
 - first public version of packJPG
 - minor improvements to overall compression
 - minor bugfixes

v2.2  (08/05/2007) (public)
 - around 40% faster compression & decompression
 - major improvements to overall compression (around 2% on average)
 - reading from stdin, writing to stdout
 - smaller executable
 - minor bugfixes
 - various minor improvements
 
v2.3  (09/18/2007) (public)
 - compatibility with JPEG progressive mode
 - compatibility with JPEG extended sequential mode
 - compatibility with the CMYK color space
 - compatibility with older CPUs
 - around 15% faster compression & decompression 
 - new switch: [-d] (discard meta-info)
 - various bugfixes

v2.3a (11/21/2007) (public)
 - crash issue with certain images fixed
 - compatibility with packJPG v2.3 maintained

v2.3b (12/20/2007) (public)
 - some minor errors in the packJPG library fixed
 - compatibility with packJPG v2.3 maintained
 
v2.4 (03/24/2010) (public)
 - major improvements to overall compression (1--2%)
 - around 10% faster compression & decompression
 - major improvements to JPG compatibility
 - size of executable reduced to ~33%
 - new switch: [-ver] (verify file after processing)
 - new switch: [-np] (no pause after processing)
 - new progress bar output mode
 - arithmetic coding routines rewritten from scratch
 - various smaller improvements to numerous to list here
 - new SFX (self extracting) archive format
 
v2.5 (11/11/2011) (public)
 - improvements to overall compression (~0.5%)
 - several minor bugfixes
 - major code cleanup
 - removed packJPX from the package
 - added packARC to the package
 - packJPG is now open source!
 
v2.5a (11/21/11) (public)
 - source code compatibility improvements (Gerhard Seelmann)
 - avoid some compiler warnings (Gerhard Seelmann)
 - source code clean up (Gerhard Seelmann)
 
v2.5b (01/27/12) (public)
 - further removal of redundant code
 - some fixes for the packJPG static library
 - compiler fix for Mac OS (thanks to Sergio Lopez)
 - improved compression ratio calculation
 - eliminated the need for temp files
 
v2.5c (04/13/12) (public)
 - various source code optimizations
 
v2.5d (07/03/12) (public)
 - fixed a rare bug with progressive JPEG
 
v2.5e (07/03/12) (public)
 - some minor source code optimization
 - changed packJPG licensing to LGPL
 - moved packARC to a separate package
 
v2.5f (02/24/13) (public)
 - fixed a minor bug in the JPG parser (thanks to Stephan Busch)
 
v2.5g (09/14/13) (public)
 - fixed a rare crash bug with manipulated JPEG files
 
v2.5h (12/07/13) (public)
 - added a warning for inefficient huffman coding (thanks to Moinak Ghosh)
 
v2.5i (12/26/13) (public)
 - fixed possible crash with malformed JPEG (thanks to Moinak Ghosh)
 
v2.5j (01/15/14) (public)
 - various source code optimizations (using cppcheck)

v2.5k (01/22/16) (public)
 - Updated contact info
 - fixed a minor bug