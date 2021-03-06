[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![HitCount](http://hits.dwyl.io/nulLeeKH/mbed-braille-conversion-unit.svg)](http://hits.dwyl.io/nulLeeKH/mbed-braille-conversion-unit)
![GitHub last commit](https://img.shields.io/github/last-commit/nulLeeKH/mbed-braille-conversion-unit.svg)

# mbed-braille-conversion-unit
The braille conversion device which developed by "Seoul Hardware Hackathon" in 2019.

## H/W Spec
- B-L475E-IOT01A Discovery Kit for IoT Node - STMicro × 1
- SN74HC595N × 5
- C503C-WAN-CBBDB231 * 5 × 6
- R1966FBLKBLKIF × 1
- SE-9VBAT-Cable × 1
- MIC5504-3.3YM5 TR × 1

## Communication Protocol
- Use 9600 baud standard serial connection.
- In Braille, expressed as 0 and 1 counterclockwise from the point on the top left.
- Each character is separated by ',' and is bound by '[' and ']'.
- Each spot is seperated by ',' and is bound by '[' and ']'.
- Five characters can be expressed.

### Examples

#### Korean

##### "서울"
```
[[0,0,0,0,0,1],[0,1,1,1,0,0],[1,1,0,1,1,0],[1,0,1,1,0,0],[0,1,0,0,0,0]]
```

#### "잔디"
```
[[1,0,1,0,0,0],[1,1,0,0,0,1],[1,0,0,1,0,0],[0,1,0,1,0,0],[1,0,1,0,1,0]]
```

#### English

##### "SEOUL"
```
[[0,1,1,1,0,0],[1,0,0,0,1,0],[1,0,1,0,1,0],[1,0,1,0,0,1],[1,1,1,0,0,0]]
```

##### "GRASS
```
[[1,1,0,1,1,0],[1,1,1,0,1,0],[1,0,0,0,0,0],[0,1,1,1,0,0],[0,1,1,1,0,0]]
```

## Patch Note

### v1.0.0-alpha
- Initial release
