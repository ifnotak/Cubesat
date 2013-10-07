#include "PAY.h"


PAY::PAY(void)
{
}


PAY::~PAY(void)
{
}

int PAY::_DeletePhotos(string dir) {
    //rm /home/hamzawey/Desktop/integration/Test/*
    //string command = malloc(256*sizeof(char));	
    char command[STRING_SIZE];
    command[0] = '\0';
    strcat(command, "rm ");
    strcat(command, dir);
    strcat(command, "/* ");
    if (system(command) < 0) {
        printf("Delete photos error%s\n", strerror(errno));
        return 0;
    }
    return 1;
}

int PAY::_Rename(string dir, string frames, string newname) {
    char *dir2 = "downlink";
    char arg1[STRING_SIZE];
    char arg2[STRING_SIZE];
    char command1[STRING_SIZE];
    command1[0] = '\0';
    arg1[0] = '\0';
    arg2[0] = '\0';

    int i = strlen(frames);

    strcat(arg1, dir);

    if (i == 1) {
        strcat(arg1, "/0000000");
    } else if (i == 2) {
        strcat(arg1, "/000000");
    } else if (i == 3) {
        strcat(arg1, "/00000");
    } else if (i == 4) {
        strcat(arg1, "/0000");
    } else if (i == 5) {
        strcat(arg1, "/000");
    } else if (i == 6) {
        strcat(arg1, "/00");
    }

    strcat(arg1, frames);
    strcat(arg1, ".jpg");

    strcat(arg2, dir2);
    strcat(arg2, newname);

    strcat(command1, "mv ");
    strcat(command1, arg1);
    strcat(command1, " ");
    strcat(command1, arg2);
    //printf("%s\n", command1);
    if (system(command1) < 0) {
        printf("Rename Error error%s\n", strerror(errno));
        return 0;
    }

    return 1;
};

int PAY::_TakePhoto_2(string dir, string format, string frames, string device) {

	//mkdir downlink
	//mkdir DIR
    //mplayer -vo jpeg:outdir=/home/test -tv device=/dev/video0 -frames 20 tv://
	//mplayer -vo FORMAT:outdir=DIR -tv device=DEVICE -frames FRAMES  tv://

	string mkDownLink = "mkdir downlink";
	string mkDIR = "mkdir ";
	string command = "mplayer -vo ";
	
	mkDIR += dir;

	command += format;
	command += ":outdir=";
	command += dir;
	command += " -tv device=";
	command += device;
	command += " -frames ";
	command += frames;
	command += " tv://";
    
	system(mkDownLink.c_str());
	system(mkDIR.c_str());

	if (system(command.c_str()) < 0) {
		cout << "mplayer error: " << strerror(errno) << '\n';
        return 0;
    }
    return 1;
}

int PAY::_TakePhoto(string dir, string format, string frames, string device, string NewName) {
    if (_TakePhoto_2(dir, format, frames, device) &&
            _Rename(dir, frames, NewName) &&
            _DeletePhotos(dir))
        return 1;

    return 0;
}
