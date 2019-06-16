    #include "mbed.h"
    #include "ShiftReg.h"
     
    #define MY_DEBUG 0
     
    ShiftReg::ShiftReg
     (PinName data
    ,PinName store
    ,PinName clock
    ): _ds(data), _st(store), _sh(clock)
    {
    }
     
     
    void ShiftReg::ShiftByte
    (int8_t  data
    ,BitOrd  ord
    )
    {
        uint8_t mask;
        
        if (ord == MSBFirst) mask = 0x80;
        else                 mask = 0x01;
        
        for (int i = 0; i < 8; i++)
        {
            if (data & mask) _ds = 1;
            else             _ds = 0;
     
    #if MY_DEBUG > 0
            printf("%d ", _ds.read());
    #endif /* MY_DEBUG */
     
            if (ord == MSBFirst) mask = mask >> 1;
            else                 mask = mask << 1;
            
            _sh = 0;
            _sh = 1;
        }
     
    #if MY_DEBUG > 0
        printf("\n");
    #endif /* MY_DEBUG */
     
    }
     
    void
    ShiftReg::ShiftBit
     (int8_t  data
    )
    {
        _ds = data;
        _sh = 0;
        _sh = 1;
    }
     
    void 
    ShiftReg::Latch
     (
    )
    {
      _st = 1;
      _st = 0;
    }