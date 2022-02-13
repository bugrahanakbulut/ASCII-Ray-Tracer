# ASCII-Ray-Tracer
Simple Ray Tracing implementation to draw scene with ASCII characters by using C++ &amp; SFML. 

<p align="center">
    <img src="https://github.com/bugrahanakbulut/ASCII-Ray-Tracer/blob/main/resources/gif/SphereMovement.gif" alt="animated" />
</p>

## Camera and Scene SetUp

In this project, I created a simple scene and camera setup by using SFML. SFML provides a simple interface to the various components of your PC, to ease the development of games and multimedia applications. For the representation scene and 3D objects in it, I choose the Orthogonal Camera Projection for keeping implementation for the beginning.

## RayTracing
To implement ray tracing algorithm I followed some basic steps : 
  - Calculating pixel's world positions
  - Sending ray from that pixel world coords with same direction with camera
  - Checking ray geometry intersections in scene
  - Lightning (for shading used Blinn Phong)


<p align="center">
    <img src="https://github.com/bugrahanakbulut/ASCII-Ray-Tracer/blob/main/resources/gif/Ray_trace_diagram.svg.png" />
</p>

## TODO

This project still in under development so there might be some naughty bugs :D. If you met some of them or you need to implement any feature top of it, and if you get stuck please feel free to contact. There are some feature I will be implement in near future :
    
- [ ] Performance Optimizations (run in gpu and multithreaded)
- [ ] Adding Different Geometries (cube, plane etc.)
- [ ] Adding Mesh Supports
- [ ] Adding Perspective Camera Projection
    
    
## Contact & Some Additional Notes
The project is done for educational purpose and may include some files that I do not own. If you own anything and don't want it to be in the project or if you have any questions or comments, please feel free to contact me.

## Credits

http://blog.three-eyed-games.com/2018/05/03/gpu-ray-tracing-in-unity-part-1/




