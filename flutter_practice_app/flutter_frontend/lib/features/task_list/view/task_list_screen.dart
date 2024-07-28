import 'package:flutter/material.dart';
import 'package:flutter_practice_app/features/profile/view/profile_screen.dart';
import 'package:provider/provider.dart';
import '../../../providers/task_provider.dart';
import '../../../models/task_model.dart';
import 'task_create_screen.dart';
import 'task_edit_screen.dart';

class TaskListScreen extends StatelessWidget {
  const TaskListScreen({Key? key, required String title});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Tasks'),
        actions: [
          IconButton(
            icon: const Icon(Icons.account_circle),
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) => const ProfileScreen(title: 'Profile',),
                ),
              );
            },
          ),
        ],
      ),
      body: Stack(
        children:[
          Consumer<TaskProvider>(
            builder: (context, taskProvider, child) {
              return ListView.builder(
                itemCount: taskProvider.tasks.length,
                itemBuilder: (context, index) {
                  final task = taskProvider.tasks[index];
                  return ListTile(
                    title: Text(task.title),
                    subtitle: Text(task.description),
                    trailing: Checkbox(
                      value: task.completed,
                      onChanged: (bool? value) {
                        final updatedTask = Task(
                          id: task.id,
                          title: task.title,
                          description: task.description,
                          completed: value ?? false,
                        );
                        taskProvider.updateTask(updatedTask);
                      },
                    ),
                    onTap: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => TaskEditScreen(task: task),
                        ),
                      );
                    },
                    onLongPress: () {
                      taskProvider.deleteTask(task.id);
                    },
                  );
                },
              );
            },
          ),
          Positioned(
            bottom: 20,
            right: 20,
            child: ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => const TaskCreateScreen(),
                  ),
                );
              },
              style: ElevatedButton.styleFrom(
                shape: const CircleBorder(),
                padding: const EdgeInsets.all(16),
              ),
              child: const Icon(Icons.add),
            ),
          ),
        ],
      ),
    );
  }
}