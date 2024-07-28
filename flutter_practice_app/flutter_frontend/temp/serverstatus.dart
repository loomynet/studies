import 'package:flutter/material.dart';
import 'package:http/http.dart' as http; // Add this line to import the http package

class CryptoCoinScreen extends StatefulWidget {
  const CryptoCoinScreen({super.key});

  @override
  State<CryptoCoinScreen> createState() => _CryptoCoinScreenState();
}

class _CryptoCoinScreenState extends State<CryptoCoinScreen> {
  String? coinName;
  String _connectionStatus = 'Press the button to check server connection';

  @override
  void didChangeDependencies() {
    final args = ModalRoute.of(context)?.settings.arguments;
    assert(args != null && args is String, 'You must provide a String args');
    coinName = args as String;
    setState(() {});
    super.didChangeDependencies();
  }

  Future<void> _checkServerConnection() async {
    final url = Uri.parse('http://10.0.2.2:3000');
    try {
      final response = await http.get(url);
      if (response.statusCode == 200) {
        setState(() {
          _connectionStatus = 'Connection successful: ${response.body}';
        });
      } else {
        setState(() {
          _connectionStatus = 'Failed to connect: ${response.statusCode}';
        });
      }
    } catch (e) {
      setState(() {
        _connectionStatus = 'Error: $e';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(coinName ?? '...'),
        centerTitle: true,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(_connectionStatus),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: _checkServerConnection,
              child: const Text('Check Server Connection'),
            ),
          ],
        ),
      ),
    );
  }
}