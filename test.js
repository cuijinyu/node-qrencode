const qr = require("./build/Release/qr.node");

let qrt = new qr.Libqr();
(() => {
    let time = Date();
    for(let i = 0; i < 10000; i++) {
        qrt.getQrCode("http://www.baidu.com" + i, __dirname + '/svg/temp' + i + '.svg');
    }
    console.log(Date(), time);
})()