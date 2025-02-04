import 'dart:io';

import 'package:shelf/shelf.dart';
import 'package:shelf/shelf_io.dart';
import 'package:shelf_router/shelf_router.dart';

// Configure routes.
final _router = Router()
  ..get('/', _rootHandler)
  ..get('/echo/<message>', _echoHandler);

Response _rootHandler(Request request) {
  return Response.ok(goodName(request.requestedUri.toString()));
}

Response _echoHandler(Request request) {
  final message = params(request, 'message');
  return Response.ok((request.toString()));
}

void main(List<String> args) async {
  // Use any available host or container IP (usually `0.0.0.0`).
  final ip = InternetAddress.anyIPv4;

  // Configure a pipeline that logs requests.
  final _handler = Pipeline().addMiddleware(logRequests()).addHandler(_router);

  // For running in containers, we respect the PORT environment variable.
  final port = int.parse(Platform.environment['PORT'] ?? '8080');
  final server = await serve(_handler, ip, port);
  print('Server listening on port ${server.port}');
}

String? goodName(String name) {
  Map<String, String> map = {
    'Рома': 'Ромашка - милашка',
    'Фидор': 'Фидор - пидор',
    'Паша': 'Пашка - какашка',
    'Федя': 'Федя - говноедя',
    'Павел': 'Павел - какавел',
    'мама': 'Мамашка - милашка',
    'bob': 'Bob is good person',
  };
  return map[name] ?? 'error';
}
