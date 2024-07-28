import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:flutter_practice_app/models/task_model.dart';
import 'package:flutter_practice_app/providers/task_provider.dart';

class TaskCreateScreen extends StatefulWidget {
  const TaskCreateScreen({super.key});

  @override
  _TaskCreateScreenState createState() => _TaskCreateScreenState();
}

class _TaskCreateScreenState extends State<TaskCreateScreen> {
  final TextEditingController _titleController = TextEditingController();
  final TextEditingController _descriptionController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Create Task'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _titleController,
              decoration: const InputDecoration(labelText: 'Title'),
            ),
            TextField(
              controller: _descriptionController,
              decoration: const InputDecoration(labelText: 'Description'),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                final newTask = Task(
                  id: '',
                  title: _titleController.text,
                  description: _descriptionController.text,
                  completed: false,
                );
                Provider.of<TaskProvider>(context, listen: false).addTask(newTask);
                Navigator.pop(context);
              },
              child: const Text('Create Task'),
            ),
          ],
        ),
      ),
    );
  }
}
