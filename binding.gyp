{
  "targets": [{
    "target_name": "libqr",
    "type": "static_library",
    'conditions': [
      ['OS=="mac"', {
        'libraries': [
          "./deps/lib/libqrencode.dylib"
        ],
      }],
      ['OS=="linux"', {
        'libraries': [
          "./deps/lib/libqrencode.so"
        ],
      }],
      ['OS=="windows"', {
        'libraries': [
          "./deps/lib/libqrencode.lib"
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