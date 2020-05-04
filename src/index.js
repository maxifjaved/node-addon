var addon = require('bindings')('handler');

try {
	console.log(
		addon((arg) => {
			console.log('arg', arg);
		})
	);
} catch (error) {
	console.log('error', error.toString());
}
