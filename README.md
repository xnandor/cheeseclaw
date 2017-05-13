# cheeseclaw
Game Library

# Classes

claw::Claw -- memory owner model

claw::Maph   --  vec, mat, rect, union geom

claw::Window  -- Encapsulates SDL_Window

claw::Component -- Holds references to windows and surfaces and manages memory with ownership

claw::Viewport -- Extends component and binds to GL for 3D.

claw::Context -- Used for 2D drawing.

claw::SceneGraph

claw::Room

claw::Camera

claw::Sprite

claw::Mesh

claw::GameLoop

claw::Drawable -- pure virtual

claw::Touchable -- pure virtual

claw::Updatable -- pure virtual

# Style

Egyptian Brackets

Functions only edit through returns. C++ style as opposed to C style.

Claw object is owner model. Objects are dynamically constructed by passing in Claw Owner.

Std library should be used when availible. For collections, sorts, regex etc.


