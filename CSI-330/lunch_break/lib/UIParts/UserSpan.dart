import 'package:flutter/material.dart';
import 'package:lunch_break/Data/UserDataModel.dart';

const double SCREEN_SIZE_FRACTION = 0.17;

class UserSpan extends StatefulWidget {
  final UserData data;

  const UserSpan(this.data, {Key key}) : super(key: key);

  @override
  _UserSpanState createState() => _UserSpanState();
}

class _UserSpanState extends State<UserSpan> {
  bool _expanded;

  @override
  initState() {
    _expanded = false;
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      // height: _expanded ? (MediaQuery.of(context).size.height * SCREEN_SIZE_FRACTION) * 2 : MediaQuery.of(context).size.height * SCREEN_SIZE_FRACTION,
      child: Card(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            SizedBox(
              height: MediaQuery.of(context).size.height * SCREEN_SIZE_FRACTION,
              child: SizedBox.expand(
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Flexible(
                      flex: 4,
                      child: Padding(
                        padding: const EdgeInsets.all(4.0),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text(
                              widget.data.name.toUpperCase(),
                              style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
                            ),
                            Flexible(flex: 5, child: Image.asset(widget.data.picUrl)),
                          ],
                        ),
                      ),
                    ),
                    Flexible(
                      flex: 5,
                      child: SizedBox.expand(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Flexible(
                              child: Text(
                                widget.data.statusTxt,
                                style: TextStyle(fontSize: 20),
                              ),
                            ),
                            if (widget.data.detailsTxt.length > 0)
                              Flexible(
                                  child: IconButton(
                                icon: Icon(_expanded ? Icons.arrow_drop_up : Icons.arrow_drop_down),
                                onPressed: () => setState(() => _expanded = !_expanded),
                              ))
                          ],
                        ),
                      ),
                    ),
                    IconSet(
                      widget: widget,
                      flex: 5,
                    ),
                  ],
                ),
              ),
            ),
            if (_expanded)
              SizedBox(
                height: MediaQuery.of(context).size.height * SCREEN_SIZE_FRACTION,
                child: SizedBox.expand(
                  child: Padding(
                    padding: const EdgeInsets.fromLTRB(20, 8, 4, 4),
                    child: SingleChildScrollView(
                      child: Text(
                        widget.data.detailsTxt,
                        style: TextStyle(fontSize: 25),
                      ),
                    ),
                  ),
                ),
              ),
          ],
        ),
      ),
    );
  }
}

class IconSet extends StatelessWidget {
  const IconSet({
    Key key,
    @required this.widget,
    @required this.flex,
  }) : super(key: key);

  final UserSpan widget;
  final int flex;

  @override
  Widget build(BuildContext context) {
    return Flexible(
        flex: flex,
        child: Row(
          children: [
            Flexible(
                child: Padding(
              padding: const EdgeInsets.all(4.0),
              child: FittedBox(
                  fit: BoxFit.fill,
                  child: Icon(
                    widget.data.moodIcon,
                    size: 300,
                  )),
            )),
            Flexible(
                child: Padding(
              padding: const EdgeInsets.all(4.0),
              child: FittedBox(
                  fit: BoxFit.fill,
                  child: Icon(
                    widget.data.locationIcon,
                    size: 300,
                  )),
            )),
            Flexible(
                child: Padding(
              padding: const EdgeInsets.all(4.0),
              child: FittedBox(
                  fit: BoxFit.fill,
                  child: Icon(
                    widget.data.activityIcon,
                    size: 300,
                  )),
            )),
          ],
        ));
  }
}
