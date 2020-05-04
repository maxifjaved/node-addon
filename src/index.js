var addon = require('bindings')('handler');

try {
	console.log(addon.handler(1, 10));
} catch (error) {
	console.log('error', error.toString());
}
