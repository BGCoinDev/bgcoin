Black Gold Coin version 2.0.1 is now available from:

  <https://blackgoldcoin.org/Home/Download>

This release includes new features, security update and performance
improvements:

- LWMA (versionbit)
- Seeds node

Please report bugs using the issue tracker at GitHub:

  <https://github.com/BGCoinDev/bgcoin/issues>

To receive security and update notifications, please subscribe to:

  <https://bgcoincore.org/en/list/announcements/join/>

How to install
==============

Run the installer (on Windows) or just copy over `/Applications/Bitcoin-Qt` (on macOS)
or `bgcoind`/`bgcoin-qt` (on Linux).

Running Black Gold Coin binaries on macOS requires self signing.
```
cd /path/to/bgcoin-28.0/bin
xattr -d com.apple.quarantine bgcoin-cli bgcoin-qt bgcoin-tx bgcoin-util bgcoin-wallet bgcoind test_bgcoin
codesign -s - bgcoin-cli bgcoin-qt bgcoin-tx bgcoin-util bgcoin-wallet bgcoind test_bgcoin
```

Compatibility
==============

Black Gold Coin is supported and extensively tested on operating systems
using the Linux Kernel 3.17+, macOS 11.0+, and Windows 7 and newer. Bitcoin
Core should also work on most other UNIX-like systems but is not as
frequently tested on them. It is not recommended to use Black Gold Coin on
unsupported systems.

