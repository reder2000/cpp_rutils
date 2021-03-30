# cpp_rutils
some basic cpp framework

## roost

roost is a non-conflicting replacement for sall header-only parts of [boost](https://www.boost.org/)

To update roost, the following steps are taken:
- get a fresh version of boost
- change all path/file names from *boost* to *roost* (use antrenamer for example)
- change all file contents from *boost/Boost/BOOST*  to *roost/Roost/ROOST* (use grepWin for example)
- synchronize old files (cpp_rutils) to new files (boost-X.YY/roost)
- check compilation, adding files if necessary, for all architectures

It's quite manual but it's only done if when a new boost comes out.