# Communication protocol of mbed-braille-conversion-unit

## How to communicate

- Use 9600 baud standard serial connection.
- In Braille, expressed as 0 and 1 counterclockwise from the point on the top left.
- Each character is separated by ',' and is bound by '[' and ']'.
- Each spot is seperated by ',' and is bound by '[' and ']'.
- Five characters can be expressed.

## Examples

### Korean

#### "서울"
```
[[0,0,0,0,0,1],[0,1,1,1,0,0],[1,1,0,1,1,0],[1,0,1,1,0,0],[0,1,0,0,0,0]]
```

### "잔디"
```
[[1,0,1,0,0,0],[1,1,0,0,0,1],[1,0,0,1,0,0],[0,1,0,1,0,0],[1,0,1,0,1,0]]
```

### English

#### "SEOUL"
```
[[0,1,1,1,0,0],[1,0,0,0,1,0],[1,0,1,0,1,0],[1,0,1,0,0,1],[1,1,1,0,0,0]]
```

#### "GRASS
```
[[1,1,0,1,1,0],[1,1,1,0,1,0],[1,0,0,0,0,0],[0,1,1,1,0,0],[0,1,1,1,0,0]]
```
