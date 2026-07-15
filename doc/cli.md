# Command-Line Interface 
## Problems
### Terminal Interoperability
So here's the deal with console headers:
* _Apple/Linux_ uses \<sys\/ioctl\>
* _Windows_ uses \<windows.h\>

These are two different header files, but we can use _#ifdef_ pre-processing to get the terminal variables we need on each platform.
Fortunately, we only need three terminal attributes:
* Height
* Width
* ANSI Support

Unfortunately, we need an event listener for height and width to ensure the current resolution is always scaled
to the active size of the terminal.

**SFML** can be used to facilitate cross-system networking _without_
extensive pre-processing or _make_ scripting magic, but it doesn't expose
terminal contexts-- it only handles windows and video contexts
in any visual regard. That being said...

## Infrastructure
CLI should be broken down to four main components:
1. [Terminal Event Handler](#teh-anchor)
2. [Menu Interface](#menu-anchor)
3. [Daemon Message Passer](#dmp-anchor)
4. [Bitmap-ASCII Renderer](#bar-anchor)

<a name="teh-anchor"></a>
### [Terminal Event Handler](#teh-anchor)
We can't tie a polling system to the renderer's frame rate or we'll draw improperly sized frames to standard output.  We'll also need separate Linux and Windows definitions for terminal event collection, but all other handler components _should_ be interoperable.

<a name="menu-anchor"></a>
### [Menu Interface](#menu-anchor)
The menu interface is responsible for handling user input and presents the state of the game through standard output. It is **NOT** responsible for loading the creature bitmaps from file; the process is as follows:
1. Query the Daemon Message Passer for creature/game states.
2. Query the Terminal Event Handler for terminal resizing.
3. Pass terminal dimensions and render queue to the Bitmap-ASCII Renderer.
4. Receive creature render.
5. Concatenate and display whole game state to standard output.

Figure: TUI Mockup of a Visiting Monster

![Terminal User Interface mock-up of the visited monster's status and portrait.](resources/MonsterTUIMockup.png)

<a name="dmp-anchor"></a>
### [Daemon Message Passer](#dmp-anchor)

<a name="bar-anchor"></a>
### [Bitmap-ASCII Renderer](#bar-anchor)
