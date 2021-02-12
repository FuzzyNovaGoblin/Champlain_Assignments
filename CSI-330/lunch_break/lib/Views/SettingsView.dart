import 'dart:async';

import 'package:flutter/material.dart';
import 'package:lunch_break/Data/UserDataModel.dart';
import 'package:lunch_break/Singleton.dart';
import 'package:lunch_break/UIParts/IconPicker.dart';
import 'package:lunch_break/UIParts/VisableOnMapButton.dart';

class SettingsView extends StatefulWidget {
  @override
  _SettingsViewState createState() => _SettingsViewState();
}

class _SettingsViewState extends State<SettingsView> {
  UserData get _udata => Singleton().users[0];
  TextEditingController statusController;
  TextEditingController detailsController;

  @override
  void initState() {
    statusController = TextEditingController();
    detailsController = TextEditingController();

    statusController.text = _udata.statusTxt;
    detailsController.text = _udata.detailsTxt;

    statusController.addListener(() {
      _udata.statusTxt = statusController.text.trim();
    });

    detailsController.addListener(() {
      _udata.detailsTxt = detailsController.text.trim();
    });

    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    print(_udata.statusTxt);
    return Container(
      child: ListView(
        children: [
          Row(
            children: [
              Flexible(
                  flex: 1,
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: AspectRatio(
                      aspectRatio: 1,
                      child: ClipOval(child: Image.asset(_udata.picUrl)),
                    ),
                  )),
              Flexible(
                  flex: 2,
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Container(
                        height: 50,
                        child: FittedBox(
                            fit: BoxFit.fitHeight,
                            child: Text(
                              _udata.name,
                              style: TextStyle(fontSize: 200, color: Colors.black),
                            ))),
                  ))
            ],
          ),
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Container(
              height: 75,
              child: TextField(
                controller: statusController,
              ),
            ),
          ),
          Row(
            children: [
              Flexible(
                child: Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: Container(
                    child: AspectRatio(
                      aspectRatio: 1,
                      child: IconButton(
                        tooltip: "Mood",
                        onPressed: () {
                          Navigator.push(context, MaterialPageRoute(builder: (context) => IconPicker())).then(
                            (result) {
                              if (result != null) setState(() => _udata.moodIcon = result);
                            },
                          );
                        },
                        icon: FittedBox(
                          child: Icon(
                            _udata.moodIcon,
                            size: 300,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ),
              Flexible(
                child: Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: Container(
                    child: AspectRatio(
                      aspectRatio: 1,
                      child: IconButton(
                        tooltip: "Location",
                        onPressed: () {
                          Navigator.push(context, MaterialPageRoute(builder: (context) => IconPicker())).then(
                            (result) {
                              if (result != null) setState(() => _udata.locationIcon = result);
                            },
                          );
                        },
                        icon: FittedBox(
                          child: Icon(
                            _udata.locationIcon,
                            size: 300,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ),
              Flexible(
                child: Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: Container(
                    child: AspectRatio(
                      aspectRatio: 1,
                      child: IconButton(
                        tooltip: "Activity",
                        onPressed: () {
                          Navigator.push(context, MaterialPageRoute(builder: (context) => IconPicker())).then(
                            (result) {
                              if (result != null) setState(() => _udata.activityIcon = result);
                            },
                          );
                        },
                        icon: FittedBox(
                          child: Icon(
                            _udata.activityIcon,
                            size: 300,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ),
            ],
          ),
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 15),
            child: Container(
              child: TextField(
                minLines: 10,
                maxLines: 10,
                controller: detailsController,),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Container(
              height: 75,
              child: VisableOnMapButton(callback: ()=>_udata.enableMaps = !_udata.enableMaps,),
            ),
          ),
        ],
      ),
    );
  }
}
