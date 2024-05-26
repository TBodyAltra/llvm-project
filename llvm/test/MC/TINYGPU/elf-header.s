# RUN: llvm-mc %s -filetype=obj -triple=tinygpu | llvm-readobj -h \
# RUN:     | FileCheck -check-prefix=tg01 %s