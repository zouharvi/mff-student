# Grewh2D
Genetically Refined Wheels in 2D - semi-interactive visualisation of genetic based evolution of multi-wheeled vehicles

### TODO:
- statistics screen
- smooth camera follow (maybe omit this due to performance)
- BUG: sometimes the best one doesn't carry over. This is not inheritedly bad. Maybe it's happening because of non-deterministic physics system, which drops some frames, especially on the first creature drop, resulting in it getting lost. Or some forgotten mutation, idk. 
- BUG: triangulation is sometimes not perfect

### Notes:
- unfortunately IComparable cannot be used since it breaks the WebGL build
- minimal polygon triangulation is funnily enough an open problem, doing clockwise sort instead, so that indrawable polygons are fixe

### Third party stuff:
- [Unity](https://unity3d.com/)
- [PixelFJVerdana12pt](http://www.1001fonts.com/pix-pixelfjverdana12pt-font.html)
- [Pixelate](https://ax23w4.itch.io/pixelate)
- [Trianglify](https://qrohlf.com/trianglify-generator/)
- [Simple Fade Scene Transition System](https://assetstore.unity.com/packages/tools/gui/simple-fade-scene-transition-system-81753)
- [Random From Distributions](https://assetstore.unity.com/packages/tools/random-from-distributions-statistical-distributions-random-numbe-15873)
