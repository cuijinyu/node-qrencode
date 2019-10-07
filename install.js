const process = require('child_process');

// compile the libqrencode
process.exec(
  `cd deps/libqrencode && bash ./autogen.sh && ./configure --prefix=${__dirname}/deps/bin && make -j 4 && make install`,
  (
    error,
    stdout
  ) => {
    if (error !== null) {
      console.error(
        error
      );
    }
    console.log(
      stdout
    );
  }
)