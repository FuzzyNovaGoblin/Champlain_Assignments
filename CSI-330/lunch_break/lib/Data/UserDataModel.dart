import 'package:flutter/material.dart';

class UserData {
  String picUrl;
  String name;
  String statusTxt;
  String detailsTxt;
  IconData moodIcon;
  IconData locationIcon;
  IconData activityIcon;
  bool enableMaps;

  UserData({
    @required this.picUrl,
    @required this.name,
    @required this.statusTxt,
    @required this.detailsTxt,
    @required this.moodIcon,
    @required this.locationIcon,
    @required this.activityIcon,
    @required this.enableMaps,
  });

  factory UserData.defaultuser() {
    return UserData(picUrl: "https://fuzytech.com/imgs/allyProfile.jpg", name: "name", statusTxt: "doin stuff", detailsTxt: "", moodIcon: Icons.tag_faces, locationIcon: Icons.place_outlined, activityIcon: Icons.event_seat, enableMaps: true);
  }

  // String get picUrl => _picUrl;
  // String get name => _name;
  // String get statusTxt => _statusTxt;
  // String get detailsTxt => _detailsTxt;
  // IconData get moodIcon => _moodIcon;
  // IconData get locationIcon => _locationIcon;
  // IconData get activityIcon => _activityIcon;
  // bool get enableMaps => _enableMaps;

  // void set picUrl(String v) => _picUrl =v;
  // void set name(String v) => _name =v;
  // void set statusTxt(String v) => _statusTxt =v;
  // void set detailsTxt(String v) => _detailsTxt =v;
  // void set moodIcon(IconData v) => _moodIcon =v;
  // void set locationIcon(IconData v) => _locationIcon =v;
  // void set activityIcon(IconData v) => _activityIcon =v;
  // void set enableMaps(bool v) => _enableMaps =v;
}
