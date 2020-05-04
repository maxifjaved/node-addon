var addon = require('bindings')('handler');

try {
	console.log(
		addon.handler(12, 15, (arg) => {
			console.log('arg', arg);
		})
	);
} catch (error) {
	console.log('error', error.toString());
}
