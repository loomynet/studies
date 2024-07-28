import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:flutter_practice_app/providers/task_provider.dart';
import 'router/router.dart';
import 'theme/theme.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => TaskProvider(),
      child: MaterialApp(
        title: 'Task Management',
        theme: theme,
        routes: routes,
      ),
    );
  }
}