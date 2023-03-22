const vscode = require('vscode');
const { exec } = require('child_process');
const { version } = require('./package.json');

function generateJavaDoc() {
    // Get the current open file
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
        return;
    }

    // Get the file path
    const filePath = editor.document.fileName;
    const fileName = filePath.substring(filePath.lastIndexOf("/") + 1);
    const date = new Date().toLocaleString();

    // Get the user's name and email address from VS Code settings
    const config = vscode.workspace.getConfiguration();
    const authorName = config.get('authorName') || 'Unknown';
    const email = config.get('email') || 'Unknown';

    // Execute the javadoc command
    exec(`javadoc -author ${authorName} -version ${version} -date ${date} -email ${email} ${filePath}`, (error, stdout, stderr) => {
        if (error) {
            vscode.window.showErrorMessage(`Error generating documentation: ${error}`);
            return;
        }

        // Show the documentation in a new VS Code window
        vscode.workspace.openTextDocument({ content: stdout }).then(doc => {
            vscode.window.showTextDocument(doc, { preview: false });
        });
    });
}

// Register the command for the extension
exports.activate = context => {
    context.subscriptions.push(vscode.commands.registerCommand('extension.generateJavaDoc', generateJavaDoc));
};
