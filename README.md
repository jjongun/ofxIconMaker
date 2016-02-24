#ofxIcomMaker
You can ease getting the Google Material icons now. <br />
You don't need downloading zip file and extract to png file. also don't need copy to data folder<br />
Just need to know 'icon id'.<br />
And now able to drawing all material style icons on your of apps.<br />


##Simple using
```c++
#include "ofxIconMaker.h"
ofImage* iconImage;

//
iconImage = ofxIconMaker::GetIcon(icon_id, color, dpi, type);
```

## How to get icons 
###(very simple video tutorial: https://youtu.be/2Myg8-8VGlE)



1) open any webbrowser<br />
2) go to https://design.google.com/icons/<br />
3) click any icon<br />
4) Look at webbrowser url text<br />
5) Select text after '#' and Copy to clipboard<br />
     ```
     ex) https://design.google.com/icons/#ic_copyright -> 'ic_copyright'
     ```<br />
6) Using api : ofxIconMaker::GetIcon([icon_id] , select COLOR , select DPI , select type)<br />




