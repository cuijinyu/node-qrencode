# node-qrencode

libqrencode 的 node 扩展，性能好，大约是node-qrcode的四倍性能

## 兼容性

暂时只兼容 Node v10 ，稍后会提供 Nan 编写的版本，兼容更广的 Node 版本

## API

```js
const qr = require("node-qrencode");

let qrt = new qr.Libqr();

// 暂时只支持生成 SVG
qrt.getQrCode("http://www.baidu.com", 'temp.svg');
```