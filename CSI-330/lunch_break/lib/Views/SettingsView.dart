import 'package:flutter/material.dart';
import 'package:lunch_break/UIParts/VisableOnMapButton.dart';

class SettingsView extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
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
                      child: Placeholder(),
                    ),
                  )),
              Flexible(
                  flex: 2,
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Container(height: 50, color: Colors.green, child: Placeholder()),
                  ))
            ],
          ),
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Container(
              height: 75,
              child: Placeholder(),
            ),
          ),
          Row(
            children: [
              Flexible(
                  child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  child: AspectRatio(aspectRatio: 1, child: Placeholder()),
                ),
              )),
              Flexible(
                  child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  child: AspectRatio(aspectRatio: 1, child: Placeholder()),
                ),
              )),
              Flexible(
                  child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  child: AspectRatio(aspectRatio: 1, child: Placeholder()),
                ),
              )),
            ],
          ),
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Container(
              child: Placeholder(),
            ),
          ),

          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Container(
              height: 75,
              child: VisableOnMapButton(),
            ),
          ),
        ],
      ),
    );
  }
}
