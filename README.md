#### STM32L475 bare board learning

all source from: http://www.openedv.com/posts/list/13912.htm


#### rtthread learning.
[link](https://www.rt-thread.org/document/site/)

#### flash
```
openocd -f interface/stlink-v2-1.cfg -f board/stm32l4discovery.cfg -c "program rtthread.bin exit 0x08000000"
```

