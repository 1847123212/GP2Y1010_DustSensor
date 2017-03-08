# GP2Y1010_DustSensor  
Arduino IDE 用の SHARP GP2Y1010AU0F ほこりセンサ用のライブラリです。  
version 0.1

# ライセンス  
License MIT

# 使い方

* このライブラリを Arduino IDE にインクルードしてください。
* SHARP GP2Y1010AU0F を Arduino や ESP-WROOM-02 に配線してください。

    左から  
    GP2Y1010AU0F 青 → 150Ω抵抗経由 Arduino Vout(5V), 220μFコンデンサ経由 Arduino GND  
    GP2Y1010AU0F 緑 → Arduino GND  
    GP2Y1010AU0F 白 → Arduino Digital pin  
    GP2Y1010AU0F 黄 → Arduino GND  
    GP2Y1010AU0F 黒 → Arduino Analog pin (ESP-WROOM-02の場合は TOUT: 下記注意事項参照)  
    GP2Y1010AU0F 赤 → Arduino Vout(5V)  
    
    ※注意 ESP-WROOM-02 を使用する場合  
      ESP-WROOM-02のanalog TOUTピンは1Vまでしか対応しておりません。そのため、分圧回路にて5Vを1Vまで降圧させてください。  

* Arduino IDE からスケッチ例を参照してください。

# 注意事項

* ESP-WROOM-02 でのみテストをしています。他の Arduino(もしくは互換機)で動作しない場合はご連絡ください。

# GP2Y1010_DustSensor ライブラリ説明

## コンストラクタ

* GP2Y1010_DustSensor  
  素のコンストラクタ。こちらを使って変数定義した場合は、事後に begin関数を呼び出してピンを設定してください。

* GP2Y1010_DustSensor(int ledPin, int measurePin)  
  使用するピンを設定できるコンストラクタ。  
    ledPin = 白の配線で接続したピン  
    measurePin = 黒の配線で接続したピン  

## public関数

* void begin(int ledPin, int measurePin)  
  使用するピンを設定します。  
    ledPin = 白の配線で接続したピン  
    measurePin = 黒の配線で接続したピン  
  
* float getDustDensity()  
  ほこりの濃度を取得します。単位は μg/m3 です。

# リンク
* GP2Y1010AU0F Data sheet  
  http://www.sharp.co.jp/products/device/doc/opto/gp2y1010au_j.pdf

* GP2Y1010AU0F 説明資料  
  http://www.sharp.co.jp/products/device/doc/opto/gp2y1010au_appl_j.pdf 

