#include <iostream>
#include <string>

using namespace std;

class MediaFile 
{
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

class AudioFile : public MediaFile 
{
private:
    string artist;
    int duration;
    int volume;
    int currentPosition;

public:
    AudioFile(const string& artist, int duration)
        : artist(artist), duration(duration), volume(50), currentPosition(0) {}

    void play() override 
	{
        cout << "Playing audio file by " << artist << endl;
        cout << "Duration: " << duration << " seconds" << endl;
        cout << "Volume: " << volume << endl;
        cout << "Current Position: " << currentPosition << " seconds" << endl;
    }

    void pause() override 
	{
        cout << "Pausing audio file" << endl;
    }

    void stop() override 
	{
        cout << "Stopping audio file" << endl;
        currentPosition = 0;
    }

    void adjustVolume(int newVolume) {
        volume = newVolume;
    }

    void displayCurrentPosition() const {
        cout << "Current Position: " << currentPosition << " seconds" << endl;
    }
};

class VideoFile : public MediaFile 
{
private:
    string resolution;
    int duration;
    int brightness;
    int contrast;
    int currentPosition;

public:
    VideoFile(const string& resolution, int duration)
        : resolution(resolution), duration(duration), brightness(50), contrast(50), currentPosition(0) {}

    void play() override 
	{
        cout << "Playing video file" << endl;
        cout << "Resolution: " << resolution << endl;
        cout << "Duration: " << duration << " seconds" << endl;
        cout << "Brightness: " << brightness << endl;
        cout << "Contrast: " << contrast << endl;
        cout << "Current Position: " << currentPosition << " seconds" << endl;
    }

    void pause() override 
	{
        cout << "Pausing video file" << endl;
    }

    void stop() override 
	{
        cout << "Stopping video file" << endl;
        currentPosition = 0;
    }

    void adjustBrightness(int newBrightness) 
	{
        brightness = newBrightness;
    }

    void adjustContrast(int newContrast)
	{
        contrast = newContrast;
    }

    void displayCurrentPosition() const 
	{
        cout << "Current Position: " << currentPosition << " seconds" << endl;
    }
};

const int MAX_MEDIA_FILES = 100;

class MediaLibrary 
{
private:
    MediaFile* mediaFiles[MAX_MEDIA_FILES];
    int numFiles;

public:
    MediaLibrary() : numFiles(0) {}

    void addMediaFile(MediaFile* file) 
	{
        if (numFiles < MAX_MEDIA_FILES) 
		{
            mediaFiles[numFiles] = file;
            numFiles++;
        }
    }

    void playMediaFile(int index) 
	{
        if (index >= 0 && index < numFiles) 
		{
            mediaFiles[index]->play();
        } else {
            cout << "Invalid media file index" << endl;
        }
    }

    void displayAllMediaFiles() const 
	{
        cout << "Media Library:" << endl;
        for (int i = 0; i < numFiles; i++) 
		{
            cout << "Media File #" << i << endl;
            mediaFiles[i]->play();
            cout << endl;
        }
    }
};

int main() {
    MediaLibrary library;

    AudioFile audio("Artist Name", 180);
    VideoFile video("1920x1080",600);
    library.addMediaFile(&audio);
	library.addMediaFile(&video);
	
	int choice;
	cout << "Enter 0 to play audio file, 1 to play video file: ";
	cin >> choice;
	
	if (choice == 0) 
	{
	    library.playMediaFile(0);
	} 
	else if (choice == 1) 
	{
	    library.playMediaFile(1);
	} 
	else 
	{
	    cout << "Invalid choice" << endl;
	}
	
	int volume;
	cout << "Enter volume for audio file: ";
	cin >> volume;
	audio.adjustVolume(volume);
	audio.displayCurrentPosition();
	
	int brightness;
	cout << "Enter brightness for video file: ";
	cin >> brightness;
	video.adjustBrightness(brightness);
	video.displayCurrentPosition();
	
	library.displayAllMediaFiles();

return 0;
}


