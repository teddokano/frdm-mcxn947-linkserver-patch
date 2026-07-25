# frdm-mcxn947-linkserver-patch

A local patch that enables uploading to the FRDM-MCXN947 via NXP LinkServer
from the Arduino IDE (`arduino:zephyr_contrib`, ArduinoCore-zephyr).

Background and detailed steps: https://qiita.com/teddokano/items/50a49815526f66ca692c

## Environment

- macOS
- Arduino IDE 2.x
- `arduino:zephyr_contrib` 0.56.0 (if your version differs, adjust the destination path accordingly)
- [NXP LinkServer](https://www.nxp.com/linkserver) must already be installed

## Installation

Copy the 3 files in this repository directly into the following directory.

```
~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/
├── boards.local.txt          ← copy
├── platform.local.txt        ← copy
└── tools/
    └── upload_linkserver.sh  ← copy (make sure to grant execute permission)
```

```bash
cp boards.local.txt platform.local.txt \
   ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/
mkdir -p ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools
cp tools/upload_linkserver.sh \
   ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools/
chmod +x ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools/upload_linkserver.sh
```

After copying, in the Arduino IDE select any option under `Tools > Programmer`,
then run `Tools > Burn Bootloader`.

## Using this with other boards

Replace `MCXN947:FRDM-MCXN947` in `boards.local.txt` and
`tools/upload_linkserver.sh` with the identifier for your target board, which
you can check with the `LinkServer devices` command.

## About Windows support

This patch has only been verified on macOS. Supporting Windows would require
adding `tools.linkserver.upload.pattern.windows` to `platform.local.txt` and
providing an `upload_linkserver.bat` script.

## Background and troubleshooting details

The reasoning behind why this patch is needed, along with the pitfalls
encountered along the way, are documented in the article below.

👉 (Qiita article URL here)

## License

MIT
