import '../features/login/login.dart';
import '../features/register/register.dart';
import '../features/task_list/task_list.dart';
import '../features/profile/profile.dart';


final routes = {
  '/': (context) => const LoginPage(title: 'Login Page'),
  '/register': (context) => const RegisterPage(title: 'Register Page'),
  '/list': (context) => const TaskListScreen(title: 'Task List Page'),
  '/profile': (context) => const ProfileScreen(title: 'Profile Page'),
};