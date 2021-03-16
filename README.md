# AMT630A SDK

## Custom firmware for AMT630A based 5" TFT Monitor

The AMT630A is a video display controller found on many small cheep TFT monitors for car rear view cameras. Some times these monitors lacks on software features or have weird behavior that we which could fix, and for that having the firmware source code is a dream.

### Screen size

The original SDK has parameters for 4.3" and 7" display sizes, for my 5" display I had to extract the parameters from the binary flash content.
Before having the SDK,I wrote a disassembler (dss52) similar to [no$x51](https://problemkaputt.de/x51.htm) in an attempt to reverse engineering the firmware, this tool later help me locate the display parameters.

### Build

The code compiles using keil uVision v5.27

### Links

[NesDev - AMT630A firmware for mini TFT screens](http://forums.nesdev.com/viewtopic.php?f=23&t=16825)<br>
[NOCASH - AMT60A Chip specifications](https://problemkaputt.de/x51specs.htm#amt630amemorymap)<br>

---
Licensed under the MIT license.