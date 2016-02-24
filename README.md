#ofxIcomMaker

simple using
```c++
#include "ofxIconMaker.h"
ofImage* iconImage;

//
iconImage = ofxIconMaker::GetIcon(icon_id, color, dpi, type);
```

## how to using

video tutorial : https://youtu.be/2Myg8-8VGlE

1) open any webbrowse

2) go to https://design.google.com/icons/

3) click any icon

4) Look at webbrowser url text

5) Select text after '#' and Copy to clipboard

     ex) https://design.google.com/icons/#ic_copyright -> 'ic_copyright'
  
6) Using api : ofxIconMaker::GetIcon([icon_id] , select COLOR , select DPI , select type)




