#ofxIcomMaker
You can ease getting Google Material icons now. <br />
Just need know and copy and paste 'icon id'.<br />
And now able to drawing all material style icons on your of apps.<br />


simple using
```c++
#include "ofxIconMaker.h"
ofImage* iconImage;

//
iconImage = ofxIconMaker::GetIcon(icon_id, color, dpi, type);
```

## how to using (video : https://youtu.be/2Myg8-8VGlE)



1) open any webbrowse<br />
2) go to https://design.google.com/icons/<br />
3) click any icon<br />
4) Look at webbrowser url text<br />
5) Select text after '#' and Copy to clipboard<br />
     ex) https://design.google.com/icons/#ic_copyright -> 'ic_copyright'<br />
6) Using api : ofxIconMaker::GetIcon([icon_id] , select COLOR , select DPI , select type)<br />




