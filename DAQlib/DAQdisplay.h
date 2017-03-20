#ifndef DAQ_DISPLAY_H_NIX
#define DAQ_DISPLAY_H_NIX

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

int daqd_startWindow(int type)
{
	unsigned long daqd_background, daqd_border;
	Display *daqd_disp;
	int daqd_screen;
	Window daqd_win;
	GC daqd_gc;
	XEvent daqd_ev;
	int daqd_height, daqd_width;

	daqd_disp = XOpenDisplay(NULL);
	if(!daqd_disp)
	{
		fprintf(stderr, "Unable to connect to display\n");
		return 0;
	}

	daqd_screen = DefaultScreen(daqd_disp);
	daqd_background = BlackPixel(daqd_disp, daqd_screen);
	daqd_border = WhitePixel(daqd_disp, daqd_screen);

	daqd_width = 40;
	daqd_height = 40;

	daqd_win = XCreateSimpleWindow(daqd_disp, DefaultRootWindow(daqd_disp), 
							0,0, // x,y
							daqd_width, daqd_height, 
							2, daqd_border, // border width, colour
							daqd_background);  //

	XSelectInput(daqd_disp, daqd_win, ButtonPressMask|StructureNotifyMask);
	XMapWindow(daqd_disp, daqd_win);

while(1){
		XNextEvent(daqd_disp, &daqd_ev);
		switch(daqd_ev.type){
		case ConfigureNotify:
			if (daqd_width != daqd_ev.xconfigure.width
					|| daqd_height != daqd_ev.xconfigure.height) {
				daqd_width = daqd_ev.xconfigure.width;
				daqd_height = daqd_ev.xconfigure.height;
				printf("Size changed to: %d by %d", daqd_width, daqd_height);
			}
			break;
		case ButtonPress:
			XCloseDisplay(daqd_disp);
			return 0;
		}
	}
							
	return 1;
}


#endif
