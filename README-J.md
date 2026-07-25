# frdm-mcxn947-linkserver-patch

FRDM-MCXN947 を Arduino IDE (`arduino:zephyr_contrib`, ArduinoCore-zephyr) 上で
NXP LinkServer 経由でアップロードできるようにするローカルパッチです。

背景・詳しい手順はこちら: https://qiita.com/teddokano/items/50a49815526f66ca692c

## 動作環境

- macOS
- Arduino IDE 2.x
- `arduino:zephyr_contrib` 0.56.0 (バージョンが異なる場合はコピー先パスを読み替えてください)
- [NXP LinkServer](https://www.nxp.com/linkserver) インストール済みであること

## インストール方法

このリポジトリの3ファイルを、以下のディレクトリにそのままコピーしてください。

```
~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/
├── boards.local.txt          ← コピー
├── platform.local.txt        ← コピー
└── tools/
    └── upload_linkserver.sh  ← コピー(実行権限を付与すること)
```

```bash
cp boards.local.txt platform.local.txt \
   ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/
mkdir -p ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools
cp tools/upload_linkserver.sh \
   ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools/
chmod +x ~/Library/Arduino15/packages/arduino/hardware/zephyr_contrib/0.56.0/tools/upload_linkserver.sh
```

コピー後、Arduino IDEで `Tools > Programmer` から何か選択し、`Tools > Burn Bootloader` を実行してください。

## 他のボードで使う場合

`boards.local.txt` と `tools/upload_linkserver.sh` 内の `MCXN947:FRDM-MCXN947` を、
`LinkServer devices` コマンドで確認した対象ボードの識別子に置き換えてください。

## Windows対応について

このパッチは macOS のみ検証済みです。Windows対応には `platform.local.txt` に
`tools.linkserver.upload.pattern.windows` の追加と、`upload_linkserver.bat` の用意が必要です。

## 詳しい背景・トラブルシューティング

なぜこのパッチが必要か、作業中に踏んだ落とし穴などは、こちらの記事にまとめています。

👉 (Qiita記事のURLをここに)

## License

MIT
