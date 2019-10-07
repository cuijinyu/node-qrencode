{
  "targets": [{
    "target_name": "libqr",
    'conditions': [
      ['OS=="mac"', {
        'libraries': [
          "libqrencode.dylib"
        ],
      }],
      ['OS=="linux"', {
        'libraries': [
          "libqrencode.so"
        ],
      }],
      ['OS=="windows"', {
        'libraries': [
          "libqrencode.lib"
        ],
      }]
    ],
    "include":[
      "./src/qrencode.h"
    ],
    "sources": [
      "./src/entry.cc",
      "./src/qrenc.hpp",
      "./src/libqr.cc"
    ]
  }]
}