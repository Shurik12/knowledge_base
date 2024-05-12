#pragma once

#include <string>
#include <vector>

#include <YandexMusic/DownloadInfo.h>
#include <Common/tinyxml2.h>

using namespace std;
using namespace tinyxml2;

class Track
{

public:

	Track(
		string  id_,
		string  title_,
		vector<string> artists_,
        bool available_);

	~Track()= default;

    /// Get private members of class
	[[nodiscard]] string getId() const;
	[[nodiscard]] string getTitle() const;
	[[nodiscard]] vector<string> getArtists() const;
    [[nodiscard]] bool getAvailable() const;

    void getTracks(vector<string> & track_ids);
    static void getSign(string & download_url, const XMLDocument & xml_response);
    void downloadTrack(string & lyrics_dir, string & tracks_dir);
    DownloadInfo getDownloadInfo();

private:

	string id;
	string title;
	vector<string> artists;
    bool available = true;
};